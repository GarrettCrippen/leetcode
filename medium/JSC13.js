/**
 * @param {Function[]} functions
 * @param {number} n
 * @return {Function}
 */

//fufill n promises at a time
var promisePool = async function(functions, n) {
    //return a new promise that resolves when all promises resolved
    return new Promise ((resolve,reject)=>{

        let i = 0;
        let inProgress = 0;

        function callback(){

            //all promises resolved
            if(i === functions.length && inProgress === 0)
                    resolve();

            while(i<functions.length && inProgress < n){
                //after resolved remove from inprogress
                functions[i++]().then( ()=>{
                    inProgress--;
                    callback();
                });
                //add to in progress
                inProgress++;
            }

        }
        callback();

    })
};

/**
 * const sleep = (t) => new Promise(res => setTimeout(res, t));
 * promisePool([() => sleep(500), () => sleep(400)], 1)
 *   .then(console.log) // After 900ms
 */