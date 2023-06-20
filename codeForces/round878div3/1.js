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
    for(let t=0;t<tt;t++){
        let n = parseInt(readline());
        let s = readline();
        let chr = null;
        let ans = ""
        for(let i=0;i<n;i++)
        {
            if(chr === null){
                chr = s[i];
                ans += chr;
            }else if(chr === s[i]){
                chr = null;
            }
        }
        console.log(ans);
    }

}