static void maxim_i(node_arbreNari* m, T& x) {
    if (m == nullptr) return;
    int n = m->seg.size();
    for (int i = 0; i < n; ++i) {
        T max = x;
        maxim_i(m->seg[i], max);
        if (max > x) x = max;
    }
    if (m->info > x) x = m->info;
}

T maxim() const {
    T max = primer_node->info;
    maxim_i(primer_node, max);
    return max;
}
