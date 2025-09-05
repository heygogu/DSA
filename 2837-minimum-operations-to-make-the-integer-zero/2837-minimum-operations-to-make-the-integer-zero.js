/**
 * @param {number} num1
 * @param {number} num2
 * @return {number}
 */
var makeTheIntegerZero = function (num1, num2) {
    const countBits = (n) => {
        return n.toString(2).split('1').length - 1;
    }

    for (let k = 1; k <= 60; k++) {
        let target = num1 - k * num2;
        if (target < k) {
            continue;
        }
        if (target >= 0 && countBits(target) <= k) {
            return k;
        }
    }
    return -1;
};