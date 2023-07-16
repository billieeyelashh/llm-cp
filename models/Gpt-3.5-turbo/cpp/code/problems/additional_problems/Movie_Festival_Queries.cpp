
   vector<pair<int, int>> movies(n);
   for (int i = 0; i < n; ++i) {
       int a, b;
       cin >> a >> b;
       movies[i] = {b, a};
   }
   sort(movies.begin(), movies.end());
   