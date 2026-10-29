
class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) ++LOG;

        vector<int> parent(n), depth(n), tin(n), tout(n);
        vector<int> mask(n);
        vector<vector<int>> up(LOG, vector<int>(n));

        int timer = 0;
        vector<pair<int, int>> st = {{0, -1}};

        while (!st.empty()) {
            auto [u, p] = st.back();
            st.pop_back();

            if (p == -2) {
                tout[u] = timer;
                continue;
            }

            parent[u] = (p == -1 ? u : p);
            depth[u] = (p == -1 ? 0 : depth[p] + 1);
            tin[u] = ++timer;

            up[0][u] = parent[u];
            for (int k = 1; k < LOG; ++k)
                up[k][u] = up[k - 1][up[k - 1][u]];

            st.push_back({u, -2});

            for (int v : adj[u]) {
                if (v == p) continue;
                st.push_back({v, u});
            }
        }

        vector<int> bit(n + 2, 0);

        auto add = [&](int i, int val) {
            for (; i <= n + 1; i += i & -i)
                bit[i] ^= val;
        };

        auto rangeXor = [&](int l, int r, int val) {
            add(l, val);
            add(r + 1, val);
        };

        auto prefixXor = [&](int i) {
            int res = 0;
            for (; i > 0; i -= i & -i)
                res ^= bit[i];
            return res;
        };

        for (int u = 0; u < n; ++u) {
            mask[u] = 1 << (s[u] - 'a');
            rangeXor(tin[u], tout[u], mask[u]);
        }

        auto getMask = [&](int u) {
            return prefixXor(tin[u]);
        };

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];
            for (int k = 0; k < LOG; ++k)
                if (diff & (1 << k))
                    u = up[k][u];

            if (u == v) return u;

            for (int k = LOG - 1; k >= 0; --k) {
                if (up[k][u] != up[k][v]) {
                    u = up[k][u];
                    v = up[k][v];
                }
            }
            return parent[u];
        };

        vector<bool> ans;

        for (const string& q : queries) {
            string type;
            int u;
            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int newMask = 1 << (c - 'a');
                int diff = mask[u] ^ newMask;

                if (diff) {
                    rangeXor(tin[u], tout[u], diff);
                    mask[u] = newMask;
                    s[u] = c;
                }
            } else {
                int v;
                ss >> v;

                int w = lca(u, v);
                int pathMask = getMask(u) ^ getMask(v) ^ mask[w];

                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};
