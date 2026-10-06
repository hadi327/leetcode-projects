var distMoney = function(money, children) {
    // Give every child $1 first
    money -= children;

    // Not enough money
    if (money < 0) {
        return -1;
    }

    // Maximum children that can receive an extra $7
    let ans = Math.min(Math.floor(money / 7), children);

    money -= ans * 7;

    // If all children got $8 but money is still left,
    // we cannot distribute it without making one child
    // have more than $8.
    if (ans === children && money > 0) {
        return children - 1;
    }

    // If exactly one child is left and it has 3 extra dollars,
    // that child would get $4. We can instead reduce one
    // $8 child to $7 and give the extra $1 to the remaining child.
    if (ans === children - 1 && money === 3) {
        return ans - 1;
    }

    return ans;
};