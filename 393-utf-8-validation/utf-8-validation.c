bool validUtf8(int* data, int dataSize) {
    int remaining = 0;

    for (int i = 0; i < dataSize; i++) {
        int byte = data[i];

        if (byte < 0 || byte > 255)
            return false;

        if (remaining == 0) {
            if ((byte >> 5) == 0b110) {
                remaining = 1;
            }
            else if ((byte >> 4) == 0b1110) {
                remaining = 2;
            }
            else if ((byte >> 3) == 0b11110) {
                remaining = 3;
            }
            else if ((byte >> 7) == 0) {
                remaining = 0;
            }
            else {
                return false;
            }
        }
        else {
            if ((byte >> 6) != 0b10)
                return false;

            remaining--;
        }
    }

    return remaining == 0;
}