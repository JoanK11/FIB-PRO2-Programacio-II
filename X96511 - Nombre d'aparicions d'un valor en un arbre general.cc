static int freq_i(node_arbreGen* n, const T& x) {
  if (n == nullptr) return 0;
  int freq = (n->info == x) ? 1 : 0;
  int m = n->seg.size();
  for (int i = 0; i < m; ++i) freq += freq_i(n->seg[i], x);
  return freq;
}

int freq(const T& x) const {
  return freq_i(primer_node, x);
}
