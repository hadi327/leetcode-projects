var numberToWords = function(num) {
    if (num === 0) return "Zero";

    const below20 = [
        "", "One", "Two", "Three", "Four",
        "Five", "Six", "Seven", "Eight", "Nine",
        "Ten", "Eleven", "Twelve", "Thirteen",
        "Fourteen", "Fifteen", "Sixteen",
        "Seventeen", "Eighteen", "Nineteen"
    ];

    const tens = [
        "", "", "Twenty", "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty",
        "Ninety"
    ];

    function convert(n) {
        if (n < 20) {
            return below20[n];
        }

        if (n < 100) {
            return tens[Math.floor(n / 10)] +
                (n % 10 ? " " + below20[n % 10] : "");
        }

        return below20[Math.floor(n / 100)] +
            " Hundred" +
            (n % 100 ? " " + convert(n % 100) : "");
    }

    let result = "";

    const units = [
        [1000000000, "Billion"],
        [1000000, "Million"],
        [1000, "Thousand"]
    ];

    for (let [value, name] of units) {
        if (num >= value) {
            result += convert(Math.floor(num / value)) + " " + name + " ";
            num %= value;
        }
    }

    if (num > 0) {
        result += convert(num);
    }

    return result.trim();
};