static pair<node_arbre*, int> arb_sumes_i(node_arbre* n) {
    if (n == nullptr) return make_pair(nullptr, 0);
    node_arbre* aux = new node_arbre;
    aux->info = n->info;
    pair<node_arbre*, int> esq = arb_sumes_i(n->segE);
    pair<node_arbre*, int> dre = arb_sumes_i(n->segD);
    aux->segE = esq.first, aux->segD = dre.first;
    aux->info += esq.second + dre.second;
    return make_pair(aux, aux->info);
}

void arb_sumes(Arbre<int>& asum) const {
    asum.primer_node = arb_sumes_i(primer_node).first;
}
