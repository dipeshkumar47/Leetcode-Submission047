class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        long long buySeparately = 1LL * need1 * cost1 + 1LL * need2 * cost2;

        long long buyAllCombined = 1LL * costBoth * max(need1, need2);

        int minNeed = min(need1, need2);
        long long buyMixed = 1LL * costBoth * minNeed
            + 1LL * (need1 - minNeed) * cost1
            + 1LL * (need2 - minNeed) * cost2;

        return min({buySeparately, buyAllCombined, buyMixed});
    }
};
