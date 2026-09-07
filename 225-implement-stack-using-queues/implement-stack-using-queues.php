class MyStack {
    private $queue = [];

    function push($x) {
        $this->queue[] = $x;

        $size = count($this->queue);

        for ($i = 0; $i < $size - 1; $i++) {
            $this->queue[] = array_shift($this->queue);
        }
    }

    function pop() {
        return array_shift($this->queue);
    }

    function top() {
        return $this->queue[0];
    }

    function empty() {
        return count($this->queue) == 0;
    }
}