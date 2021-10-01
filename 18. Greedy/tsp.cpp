int travelling Salesman Problem(int graph[][V], int s) {
  vector < int > vertex;
  for (int i = 0; i < V; i++)
    if (i != s)
      vertex.push_back(i);
  int min_path = INT_MAX;
  do {
    int current_pathweight = 0;
    int k = s;
    for (int i = 0; i < vertex.size(); i++) {
      current_pathweight += graph[k][vertex[i]];
      k = vertex[i];
    }
    current_pathweight += graph[k][s];
    min_path = min(min_path, current_pathweight);

  } while (
    next_permutation(vertex.begin(), vertex.end()));

  return min_path;
}
