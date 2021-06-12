static void buscar_i(node_arbreGen* n, bool& found, const T& x) {
    if (n != nullptr and not found) {
        if (n->info == x) found = true;
        else {
            int m = n->seg.size();
            for (int i = 0; i < m and not found; ++i)
                buscar_i(n->seg[i], found, x);
        }
    }
}

bool buscar(const T& x) {
    bool b = false;
    buscar_i(primer_node, b, x);
    return b;
}
