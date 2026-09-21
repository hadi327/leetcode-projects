var isRobotBounded = function(instructions) {
    let x = 0;
    let y = 0;

    // 0 = North
    // 1 = East
    // 2 = South
    // 3 = West
    let direction = 0;

    const dx = [0, 1, 0, -1];
    const dy = [1, 0, -1, 0];

    for (const command of instructions) {
        if (command === 'G') {
            x += dx[direction];
            y += dy[direction];
        } else if (command === 'L') {
            direction = (direction + 3) % 4;
        } else {
            direction = (direction + 1) % 4;
        }
    }

    return (x === 0 && y === 0) || direction !== 0;
};