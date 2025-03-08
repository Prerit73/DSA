const arr = [[[1, [1.1]], 2, 3], [4, 5]];

function customFlat(arr) {
    let result = [];

    // Iterate through the array
    for (let i = 0; i < arr.length; i++) {
        // If the element is an array, flatten it recursively
        if (Array.isArray(arr[i])) {
            result = result.concat(customFlat(arr[i]));
        } else {
            result.push(arr[i]); // Otherwise, push the element as is
        }
    }

    return result;
}



console.log('result ',customFlat(arr));