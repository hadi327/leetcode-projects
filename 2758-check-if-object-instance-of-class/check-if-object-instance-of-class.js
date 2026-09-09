var checkIfInstanceOf = function(obj, classFunction) {
    if (obj == null || classFunction == null) {
        return false;
    }

    let proto = Object.getPrototypeOf(obj);
    const target = classFunction.prototype;

    while (proto !== null) {
        if (proto === target) {
            return true;
        }

        proto = Object.getPrototypeOf(proto);
    }

    return false;
};