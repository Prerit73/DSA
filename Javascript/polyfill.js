const promiseAll = function (tasks) {
    const results = [];
    let completedCount = 0;

    return new Promise((resolve, reject) => {
        if (tasks.length === 0) {
            resolve([]);
            return;
        }

        tasks.forEach((task, index) => {
            Promise.resolve(task) // Ensure it's a promise
                .then((value) => {
                    results[index] = value;
                    completedCount += 1;
                    if (completedCount === tasks.length) {
                        resolve(results);
                    }
                })
                .catch((error) => {
                    reject(error); // Stops execution on first rejection
                });
        });
    });
};


function promiseAllSettled(tasks) {
    return new Promise(function (resolve) {
        const results = [];
        let completedCount = 0;

        if (tasks.length === 0) {
            resolve([]);
            return;
        }

        tasks.forEach(function (task, index) {
            Promise.resolve(task)
                .then(function (value) {
                    results[index] = { status: "fulfilled", value: value };
                })
                .catch(function (reason) {
                    results[index] = { status: "rejected", reason: reason };
                })
                .then(function () { // Instead of .finally()
                    completedCount++;
                    if (completedCount === tasks.length) {
                        resolve(results);
                    }
                });
        });
    });
}
