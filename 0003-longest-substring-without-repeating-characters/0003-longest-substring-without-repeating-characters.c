#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    if (n == 0) return 0;

    // Array to store the last seen index of each ASCII character
    int last_seen[128];
    for (int i = 0; i < 128; i++) {
        last_seen[i] = -1;
    }

    int max_len = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        unsigned char current_char = (unsigned char)s[right];

        // If the character was seen and is inside the current window
        if (last_seen[current_char] >= left) {
            left = last_seen[current_char] + 1;
        }

        // Update the last seen position
        last_seen[current_char] = right;

        // Calculate the current window length and update max_len
        max_len = MAX(max_len, right - left + 1);
    }

    return max_len;
}