/**
 * @param {number} n
 * @return {Function} counter
 */

 //closures important reach true encapsulation because default
            //member variables are public, unless youse use " # " to mark as private
            //more memory efficient/reusable for particular cases i.e. one protype
            var createCounter = function(n) {
                return function() {
                    return n++;
                };
            };
            
            /** 
             * const counter = createCounter(10)
             * counter() // 10
             * counter() // 11
             * counter() // 12
             */