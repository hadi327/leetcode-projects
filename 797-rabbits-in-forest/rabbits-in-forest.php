class Solution {

    function numRabbits($answers) {
        $count = [];
        $result = 0;

        foreach ($answers as $answer) {
            if (!isset($count[$answer]) ||
                $count[$answer] == 0) {

                $result += $answer + 1;
                $count[$answer] = $answer;
            } else {
                $count[$answer]--;
            }
        }

        return $result;
    }
}