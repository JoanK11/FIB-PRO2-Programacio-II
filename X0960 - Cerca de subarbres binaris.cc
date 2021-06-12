// https://jutge.org/problems/X09609_ca
static void sub_arrel_i(node_arbre* n, node_arbre* &r, const T& x, int dist, int& min_dist) {
    if (n == nullptr) return;
    if (n->info == x and (min_dist == -1 or dist < min_dist)) {
        r = copia_node_arbre(n);
        min_dist = dist;
    }
    else {
        sub_arrel_i(n->segE, r, x, dist + 1, min_dist);
        sub_arrel_i(n->segD, r, x, dist + 1, min_dist);
    }
}

void sub_arrel(Arbre& asub, const T& x) {
    int min_dist = -1;
    sub_arrel_i(primer_node, asub.primer_node, x, 0, min_dist);
}
