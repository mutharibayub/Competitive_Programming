'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();    
});

function readline() {
    return inputString[currentLine++];
}

function main() {
    const tt = parseInt(readline());
    for(let t=0;t<tt;t++) {
        let [rr, cc] = readline().split(" ").map(x=>parseInt(x));
        ++rr, ++cc;
        let fireCount = parseInt(readline());
        let fires = Array.from({length: fireCount}, ()=>readline().split(" ").map(x=>parseInt(x)));
        fires.sort((a, b)=>a[0]-b[0]);
        let possibs = Array.from({length: rr}, ()=>Array.from({length: cc}, ()=>Math.floor(1e9+7)));
        possibs[0][0] = 0;
        for(let fireIdx=0;fireIdx<fires.length;fireIdx++) {

            // console.log(possibs);
            // console.log(fireIdx);

            for(let r=0;r<rr;r++) { 
                for (let c=0;c<cc;c++) {
                    if(r>0 && possibs[r-1][c] < fires[fireIdx][0]) {
                        possibs[r][c] = Math.min(possibs[r][c], possibs[r-1][c]+1);
                    }
                    if(c>0 && possibs[r][c-1] < fires[fireIdx][0]) {
                        possibs[r][c] = Math.min(possibs[r][c], possibs[r][c-1]+1);
                    }
                }
            }
            if(possibs[rr-1][cc-1] < fires[fireIdx][0]) {
                break;
            }
            possibs = possibs.map(r=>r.map(c=>Math.max(c, fires[fireIdx][0])));
            if(fires[fireIdx][1] == 1) {
                possibs[fires[fireIdx][2]].forEach((ele, idx, arr)=>arr[idx]=Math.floor(1e9+7));
            } else {
                possibs.forEach((ele, idx, arr)=>arr[idx][fires[fireIdx][2]]=Math.floor(1e9+7));
            }
        }
        if(possibs[rr-1][cc-1]===Math.floor(1e9+7)) {
            for(let r=0;r<rr;r++) { 
                for (let c=0;c<cc;c++) {
                    if(r>0) {
                        possibs[r][c] = Math.min(possibs[r][c], possibs[r-1][c]+1);
                    }
                    if(c>0) {
                        possibs[r][c] = Math.min(possibs[r][c], possibs[r][c-1]+1);
                    }
                }
            }
        }
        console.log(possibs[rr-1][cc-1]===Math.floor(1e9+7)?-1:possibs[rr-1][cc-1]);
    }

}