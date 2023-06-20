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
        let s = [,]
        s[0] = [...readline()]
        s[1] = [...readline()]
        let [time, qq] = readline().split(" ").map(x=>parseInt(x));
        let different = new Set();
        let unblock = [];
        let unblockIdx = 0;
        for(let i=0;i<s[0].length;i++) {
            if(s[0][i]!==s[1][i]) {
                different.add(i);
            }
        }
        for(let q=0;q<qq;q++) {

            while(unblock.length > unblockIdx && unblock[unblockIdx][0] == q) {
                let toAdd = unblock[unblockIdx][1];
                if (s[0][toAdd] !== s[1][toAdd]) {
                    different.add(toAdd);
                }
                ++unblockIdx;
            }

            let query = readline().split(" ").map(x=>parseInt(x));
            // console.log(s[0], s[1]);
            // console.log(different);
            switch(query[0]) {
                case 1:
                    --query[1];
                    unblock.push([q+time,query[1]]);
                    different.delete(query[1]);
                    break;
                case 2:
                    for(let ii=1;ii<5;ii++) {
                        --query[ii];
                    }
                    [s[query[1]][query[2]], s[query[3]][query[4]]] = [s[query[3]][query[4]], s[query[1]][query[2]]];
                    for(let ii=0;ii<2;ii++) {
                        if(s[0][query[2+2*ii]]===s[1][query[2+2*ii]]) {
                            different.delete(query[2+2*ii]);
                        } else {
                            different.add(query[2+2*ii]);
                        }
                    }
                    break;
                case 3:
                    console.log(different.size>0?"NO":"YES");
                    break;
            }
        } 
    }

}