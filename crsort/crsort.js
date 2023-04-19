function f(L) {
    let n;
    let len = L.length;
    let m = 1;
    let sl = 1;
    let tmp;
    while (m < len) {
        n = 0;
        while (n < sl) {
            if (L[m] < L[n]){
                tmp = L[m];
                g = m;
                while (g > n) {
                    L[g] = L[g-1];
                    g --;
                }
                L[n] = tmp;
                sl ++;
                break;
            }
            n ++;
        }
        m ++;
    }
}

function main() {
    let L = [];
    let i = 1;
    let size = 1000;
    while (i <= size) {
        L.push(i);
        i ++;
    }
    L.reverse();
    f(L);
    console.log(L);
}

main();

// time 0.086
