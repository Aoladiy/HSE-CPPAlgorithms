#include <bits/stdc++.h>
using namespace std;

static int edit(const string &text, const string &pat) {
    const int n = static_cast<int>(text.size());
    const int m = static_cast<int>(pat.size());
    if (m == 0) return n;
    if (n == 0) return m;

    constexpr int W = 64;
    const int B = (m + W - 1) / W;
    int lastBits = m % W;
    if (!lastBits) lastBits = W;
    const uint64_t lastMask = (lastBits == 64) ? ~0ULL : (1ULL << lastBits) - 1;

    vector<array<uint64_t, 128> > Peq(B);
    for (auto &blk: Peq) blk.fill(0);
    for (int j = 0; j < m; j++)
        Peq[j / W][static_cast<uint8_t>(pat[j])] |= 1ULL << (j % W);

    vector<uint64_t> Pv(B, ~0ULL), Mv(B, 0ULL);
    Pv[B - 1] = lastMask;
    int score = m;

    for (int i = 0; i < n; i++) {
        const uint8_t c = text[i];
        uint64_t Ph_in = 1, Mh_in = 0;
        uint64_t add_carry = 0;

        for (int b = 0; b < B; b++) {
            const uint64_t Eq = Peq[b][c];
            const uint64_t pv = Pv[b], mv = Mv[b];
            const uint64_t Xv = Eq | mv;

            const __uint128_t wide = static_cast<__uint128_t>(pv) + (Eq & pv) + add_carry;
            const auto sum = static_cast<uint64_t>(wide);
            add_carry = (wide >> 64) & 1;

            const uint64_t Xh = (sum ^ pv) | Eq;
            uint64_t Ph = mv | ~(Xh | pv);
            uint64_t Mh = pv & Xh;

            if (b == B - 1) {
                const uint64_t bit = 1ULL << (lastBits - 1);
                score += (Ph & bit) ? 1 : 0;
                score -= (Mh & bit) ? 1 : 0;
            }

            const uint64_t Ph_out = Ph >> (W - 1);
            const uint64_t Mh_out = Mh >> (W - 1);
            Ph = (Ph << 1) | Ph_in;
            Mh = (Mh << 1) | Mh_in;
            Ph_in = Ph_out;
            Mh_in = Mh_out;

            Pv[b] = Mh | ~(Xv | Ph);
            Mv[b] = Ph & Xv;
        }
    }
    return score;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore();

    for (int q = 0; q < n; q++) {
        string a, b;
        getline(cin, a);
        getline(cin, b);
        if (a.size() > b.size()) swap(a, b);
        if (q) cout << ' ';
        cout << edit(b, a);
    }
    cout << '\n';
    return 0;
}
