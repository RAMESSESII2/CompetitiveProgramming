void radix_sort(vector<pair<pair<int, int>, int >> &a){
    int n = sz(a);
    {
        vector<pair<pair< int, int> , int>> a_new(n);
        vi bucket(n, 0);
        for(auto x: a){
            bucket[x.ff.ss]++;
        }
        vi pos(n);
        pos[0] = 0;
        loop(i, 1, n){
            pos[i] = pos[i-1] + bucket[i-1];
        }
        for(auto x: a){
            int i = x.ff.ss;
            a_new[pos[i]] = x;
            pos[i]++;
        }
        a = a_new;
    }
    {
        vector<pair<pair< int, int> , int>> a_new(n);
        vi bucket(n, 0);
        for(auto x: a){
            bucket[x.ff.ff]++;
        }
        vi pos(n);
        pos[0] = 0;
        loop(i, 1, n){
            pos[i] = pos[i-1] + bucket[i-1];
        }
        for(auto x: a){
            int i = x.ff.ff;
            a_new[pos[i]] = x;
            pos[i]++;
        }
        a = a_new;
    }
}

