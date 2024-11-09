const myPromiseAll = function (taskList) {
    //to store results
    const results = [];
    //to track how many promises have completed
    let promisesCompleted = 0;
    // return new promise
    return new Promise((resolve, reject) => {
        taskList.forEach((promise, index) => {
            //if promise passes
            promise.then((val) => {
                //store its outcome and increment the count
                results[index] = val;
                promisesCompleted += 1;
                //if all the promises are completed,
                //resolve and return the result
                if (promisesCompleted === taskList.length) {
                    resolve(results)
                }
            })//if any promise fails, reject.
                .catch(error => {
                    reject(error)
                })
        })
    });
}

const allSettled = (promises) => {
    // map the promises to return a custom response.
    const mappedPromises = promises.map((p) => Promise.resolve(p)
        .then(
            val => ({ status: 'fulfilled', value: val }),
            err => ({ status: 'rejected', reason: err })
        )
    );
    // run all the promises once with .all
    return Promise.all(mappedPromises);
}