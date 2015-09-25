int maxArea(int height[], int n) {
    int i = 0, j = n - 1;
    int area = 0;
    
    int h = 0, w = 0;
    while (i < j) {
        w = j - i;
        h = height[i] > height[j] ? height[j--] : height[i++];
        area = area > h * w ? area : h * w;
    }
    
    return area;
}
