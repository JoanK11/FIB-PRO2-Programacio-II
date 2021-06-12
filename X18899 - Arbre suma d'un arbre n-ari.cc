static pair<node_arbreNari*, T> arbsuma_i(node_arbreNari* m) {
    if (m == nullptr) return make_pair(nullptr, 0);
    node_arbreNari* aux = new node_arbreNari;
    aux->info = m->info;
    int n = m->seg.size();
    for (int i = 0; i < n; ++i) {
        pair<node_arbreNari*, T> p = arbsuma_i(m->seg[i]);
        aux->seg.push_back(p.first);
        aux->info += p.second;
    }
    return make_pair(aux, aux->info);
}

void arbsuma(ArbreNari& asum) const {
    asum.primer_node = arbsuma_i(primer_node).first;
}
