/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function(fn, t) {
    //when you see async, first thing you do is return a promise
	return async function(...args) {
        //return a new promise, resolve and reject are methods within callback
        return new Promise((resolve,reject) => {
            //reject if it reaches time limit (remember setTimout accepts a method)
            setTimeout(() =>{
                reject("Time Limit Exceeded");
                },t);
                //call function if it does not reach time limit
                fn(...args).then(resolve).catch(reject);

                //same as this, and add async to anonymous function
                // // try{
                //     res = await fn(...args);
                //     resolve(res);
                // }
                // catch(err){
                //     reject(err);
                // }

            })

    }

};

// ******use clearTimeout(id) to avoid memory leaks

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */