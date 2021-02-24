    int start = 0, end = n - 1;
    int mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        int prev = (mid + n - 1) % n;
        int next = (mid + 1) % n;

        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next])
        {
            return mid;
        }
        else if (arr[mid] >= arr[start])
        {
            start = mid + 1;
        }
        else if (arr[mid] <= arr[end])
        {
            end = mid - 1;
        }
    }