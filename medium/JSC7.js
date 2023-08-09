/**
 * @param {Function[]} functions
 * @return {Function}
 */


 //function composition ex. f(g(x))
    //syntax const composedFunc = x => f(g(x)) , where f and g are defined

    var compose = function(functions) {
        //want to evaluate right to left
        return function(x) {
            let v=x;
            for(let i =functions.length-1; i>=0; i--){
                //value v take parameter x and applies it to
                //console.log(functions[f](x));
                console.log(v);
                v = functions[i](v);
            }
            return v;
        }
    };
    
    //alternatively, we could use for(const f of functions.reverse())
    //can return another function that takes x as input and use Arra.reduceRight()
        //apply each function to the accumulator(init as x) and update accumulator with the result
        //return final accumulator
        //REDUCE RIGHT = args(reducer function, optional initial accumulator)
            //goes tright to left
    
    //consider keeping context consistnet by using call method with this/context as first param
    
    //libraries: import {compose} from 'rambda' => compose(...functions);
    // import {flowRight} from 'lodash' => folwRight(...functions);
    
    /**
     * const fn = compose([x => x + 1, x => 2 * x])
     * fn(4) // 9
     */