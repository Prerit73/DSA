function debounce(fn,delay){
    let timeId;
    return function(...args){
        console.log('Args ',args);
        clearTimeout(timeId);
        timeId = setTimeout(()=>{
            fn(...args);
        },delay)
    }
}

function print(){
    console.log('Print ',new Date().toLocaleTimeString())
}

console.log('Start ',new Date().toLocaleTimeString())
const useDebounce = debounce(print,3000);
useDebounce('Hello');
useDebounce('Start');