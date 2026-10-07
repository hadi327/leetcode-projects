var maxStability = function(n, edges, k) {
    class DSU {
        constructor(n) {
            this.parent = Array.from({ length: n }, (_, i) => i);
            this.rank = Array(n).fill(0);
        }

        find(x) {
            if (this.parent[x] !== x) {
                this.parent[x] = this.find(this.parent[x]);
            }
            return this.parent[x];
        }

        union(a, b) {
            a = this.find(a);
            b = this.find(b);

            if (a === b) return false;

            if (this.rank[a] < this.rank[b]) {
                [a, b] = [b, a];
            }

            this.parent[b] = a;

            if (this.rank[a] === this.rank[b]) {
                this.rank[a]++;
            }

            return true;
        }
    }

    // If there are mandatory edges forming a cycle,
    // no spanning tree is possible.
    const mandatory = edges.filter(e => e[3] === 1);

    const normal = edges.filter(e => e[3] === 0);

    function canAchieve(x) {
        const dsu = new DSU(n);
        let used = 0;
        let upgrades = 0;

        // Mandatory edges must be included.
        for (const [u, v, s, must] of mandatory) {
            if (s < x) return false;

            if (!dsu.union(u, v)) {
                return false;
            }

            used++;
        }

        // First use normal edges that already satisfy x.
        for (const [u, v, s] of normal) {
            if (s >= x && dsu.union(u, v)) {
                used++;
            }
        }

        // Then use weaker edges with an upgrade.
        for (const [u, v, s] of normal) {
            if (s < x && 2 * s >= x && dsu.union(u, v)) {
                upgrades++;
                used++;
            }
        }

        return used === n - 1 && upgrades <= k;
    }

    let lo = 0;
    let hi = Math.max(...edges.map(e => e[2])) * 2;

    while (lo <= hi) {
        const mid = Math.floor((lo + hi) / 2);

        if (canAchieve(mid)) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return hi;
};