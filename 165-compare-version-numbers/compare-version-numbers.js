var compareVersion = function(version1, version2) {
    const v1 = version1.split('.');
    const v2 = version2.split('.');

    const n = Math.max(v1.length, v2.length);

    for (let i = 0; i < n; i++) {
        const a = i < v1.length ? Number(v1[i]) : 0;
        const b = i < v2.length ? Number(v2[i]) : 0;

        if (a > b) return 1;
        if (a < b) return -1;
    }

    return 0;
};