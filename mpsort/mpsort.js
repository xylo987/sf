function main() {
    let L = [];
    let size = 100000000;
    for (let n = size; n > 0; n--){
        L.push(n);
    }
    mpsort(L, size);
    for(let n = 0; n < size; n++) {
        console.log(L[n]);
    }
}

function mpsort(L, size) {
    for(let count = 0; count < size-1; count++) {
        for(let n = 0; n < size-1-count; n++) {
            if (L[n] > L[n+1]) {
                let tmp = L[n];
                L[n] = L[n+1];
                L[n+1] = tmp;
            }
        }
    }
}

main()
