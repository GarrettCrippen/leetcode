/**
 * @param {number} millis
 */

//promise, you attach call backs and either fullfill or fail promise
    //resolve called if successful, reject if fails
    //.THEN called if resolved, or .CATCH if failed
//setTimeout = evalutates an expression after miliseconds
    //callback function not neccessarily exectued after timer, but added to task queue
        //this is considered 'minimum delay'
        //clearTimeout(timeoutId) => cancel operation

//java-script is single threaded

//event loop- takes first task from task queue and pushes onto call stack
    //happens whenever call stack is empty
//async - timer is an example of this (javascript doesn't wait for this)
    //aysync func returns a promise
        //if a value is return, promise is fulfilled
            //.then to use fulfilled promise
            //await to pause execution untill promise reached
                //great for fetch, or parse jason
                //syntactic sugar for .then.catch chains for promises
        //if throws an exception, then promise is rejected

//promise chaining- use keyword .then => avoids call back hell
//.finally promise executed regardless of fulfilled or rejected
    //good to clean up or log

    async function sleep(millis) {
        let condition = true;
        //construct a new promise that executes after the setTimeout
        return await new Promise((resolve,reject)=>{
            setTimeout(()=>{
                if(condition){
                    resolve('Promise fulfiled');
                }
                else{
                    reject('promise rejected');
                }},millis);
            });
    }
    
    /** 
     * let t = Date.now()
     * sleep(100).then(() => console.log(Date.now() - t)) // 100
     */