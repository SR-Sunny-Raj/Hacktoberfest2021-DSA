
#undef _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  n += 1;
  vector<int> x(n), y(n);
  for (int i = 0; i < n - 1; i++) {
    cin >> x[i] >> y[i];
  }
  int q;
  cin >> q;
  vector<int> ql(q), qr(q), qx(q);
  for (int i = 0; i < q; i++) {
    cin >> ql[i] >> qr[i] >> qx[i];
    --ql[i]; --qr[i];
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end() - 1, [&](int i, int j) {
    long long vmul = (long long) x[i] * y[j] - (long long) y[i] * x[j];
    if (vmul != 0) {
      return vmul < 0;
    }
    return (long long) x[i] * x[i] + (long long) y[i] * y[i] < (long long) x[j] * x[j] + (long long) y[j] * y[j];
  });
  rotate(order.begin(), order.end() - 1, order.end());
  vector<int> ox(n), oy(n);
  for (int i = 0; i < n; i++) {
    ox[i] = x[order[i]];
    oy[i] = y[order[i]];
  }
  vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    pos[order[i]] = i;
  }
  vector<vector<int>> q_at(n);
  for (int i = 0; i < q; i++) {
    q_at[ql[i]].push_back(i);
  }
  vector<long long> ans(q, -1);
  vector<vector<int>> check(n);
  vector<int> lft(n, -1);
  vector<int> rgt(n, -1);
  vector<bool> mark(n, true);
  vector<int> pr(n, -1), ne(n, -1);
  for (int st = 0; st < n - 1; st++) {
    for (int i : q_at[st]) {
      check[qr[i]].push_back(i);
    }
    int last = -1;
    for (int i = 0; i < n; i++) {
      pr[i] = ne[i] = -1;
      if (mark[i]) {
        pr[i] = last;
        if (last != -1) {
          ne[last] = i;
        }
        last = i;
      }
    }
    for (int fin = n - 2; fin >= st; fin--) {
      int u = pos[fin];
      lft[fin] = pr[u];
      rgt[fin] = ne[u];
      if (pr[u] != -1) {
        ne[pr[u]] = ne[u];
      }
      if (ne[u] != -1) {
        pr[ne[u]] = pr[u];
      }
      pr[u] = -1;
      ne[u] = -1;
    }
    for (int fin = st; fin <= n - 2; fin++) {
      assert(lft[fin] != -1);
      int u = pos[fin];
      ne[lft[fin]] = u;
      pr[u] = lft[fin];
      if (rgt[fin] != -1) {
        pr[rgt[fin]] = u;
        ne[u] = rgt[fin];
      }
      if (ne[u] != -1) {
        int i = order[pr[u]];
        int j = fin;
        int k = order[ne[u]];
        if ((long long) (x[j] - x[i]) * (y[k] - y[i]) - (long long) (x[k] - x[i]) * (y[j] - y[i]) > 0) {
          break;
        }
      }
      if (pr[pr[u]] != -1) {
        int i = order[pr[pr[u]]];
        int j = order[pr[u]];
        int k = fin;
        if ((long long) (x[j] - x[i]) * (y[k] - y[i]) - (long long) (x[k] - x[i]) * (y[j] - y[i]) > 0) {
          break;
        }
      }
      if (ne[u] != -1 && ne[ne[u]] != -1) {
        int i = fin;
        int j = order[ne[u]];
        int k = order[ne[ne[u]]];
        if ((long long) (x[j] - x[i]) * (y[k] - y[i]) - (long long) (x[k] - x[i]) * (y[j] - y[i]) > 0) {
          break;
        }
      }
      for (int id : check[fin]) {
        int ptr = 0;
        long long cur = -1;
        while (ne[ptr] != -1) {
          cur = (long long) (qx[id] - ox[ptr]) * (oy[ne[ptr]] - oy[ptr]) + (long long) (ox[ne[ptr]] - ox[ptr]) * oy[ptr];
          ans[id] = max(ans[id], cur);
          ptr = ne[ptr];
        }
        if (cur < 0) {
          ans[id] = -1;
        }
      }
    }
    for (int i : q_at[st]) {
      check[qr[i]].pop_back();
    }
    mark[pos[st]] = false;
  }
  for (int i = 0; i < q; i++) {
    cout << ans[i] << '\n';
  }
  debug(clock());
  return 0;
}
