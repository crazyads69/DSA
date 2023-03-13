# Cấu trúc dữ liệu và giải thuật - Buổi 01
## Trình bày bởi: Lê Minh Trí và Nguyễn Phúc Thịnh

**1. Tìm kiếm tuyến tính (Linear Search)**
- Thuật toán tìm kiếm tuyến tính là phương pháp **tìm kiếm một phần tử cho trước trong một mảng** bằng cách **duyệt lần lượt từng phần tử của mảng đó** cho đến lúc tìm thấy giá trị mong muốn hay đã duyệt qua toàn bộ mảng.
- **Ưu điểm:**
    - Dễ dàng cài đặt.
    - Nhanh khi phần tử cần tìm ở đầu mảng hoặc số lượng phần tử của mảng nhỏ.
- **Nhược điểm:**
    - Chậm đối với mảng có nhiều phần tử.
- **Đánh giá:**
    - Độ phức tạp trung bình **O(n)**.
    - Độ phức tạp trong trường hợp xấu nhất **O(n)** khi phần tử không có trong mảng hoặc nằm ở cuối mảng.
    - Độ phức tạp trong trường hợp tốt nhất **O(1)** khi phần tử nằm ở đầu mảng.
- **Ý tưởng:**
    - **Input:** Mảng A chứa các phần tử không theo thứ tự.
    - **Output:** Chỉ số của phần tử cần tìm trong mảng hoặc báo không tìm thấy. 
    - **Mô phỏng:**
        - Bắt đầu duyệt từ phần tử đầu tiên của mảng, duyệt đến cuối mảng.
        - Nếu phần tử đang duyệt bằng phần tử cần tìm thì trả về vị trí.
        - Nếu không tìm thấy bất cứ phần từ nào khi đã duyệt hết thì trả về -1.

- **Các dạng cài đặt tìm kiếm tuyến tính:**
- **Dạng vòng lặp (phổ biến nhất):** kết quả trả về là chỉ số của phần tử cần tìm.

```cpp=
int LinearSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}
```

- **Dạng cải tiến:**
    - **Ý tưởng:** 
    - Thêm phần tử **x** vào mảng **A** có **n** phần tử, khi này **A** có **n+1** phần tử. Phần tử thêm vào được gọi là phần tử cầm canh.
    - Chỉ cần điều kiện dừng là tìm thấy phần tử **x**.
```cpp=
int LinearSearch(int arr[], int n, int x)
{
    int i = 0;
    arr[n] = x;
    while (arr[i] != x)
        i++;
    if (i < n)
        return i;
    else
        return -1;
}
```

**2. Tìm kiếm nhị phân (Binary Search)**
- Thuật toán tìm kiếm nhị phân là một thuật toán **tìm kiếm xác định vị trí của một giá trị cần tìm trong một mảng đã được sắp xếp**. Thuật toán **tiến hành so sánh giá trị cần tìm với phần tử đứng giữa mảng**. Nếu hai giá trị không bằng nhau, phần nửa mảng không chứa giá trị cần tìm sẽ bị bỏ qua và tiếp tục tìm kiếm trên nửa còn lại, một lần nữa lấy phần tử ở giữa và so sánh với giá trị cần tìm, cứ thế lặp lại cho đến khi tìm thấy giá trị đó.
- **Ưu điểm:**
    - Được dùng phổ biến.
    - Nhanh đối với mảng có nhiều phần tử.
- **Nhược điểm:**
    - Cần phải sắp xếp mảng theo thứ tự.
- **Đánh giá:** 
    - Độ phức tạp trung bình **O(log(n)).**
    - Độ phức tạp trong trường hợp xấu nhất là **O(log(n))** khi tìm kiếm đến phần tử duy nhất của mảng.
    - Độ phức tạp trong trường hợp tốt nhất là **O(1)** nếu phần tử nằm ở đúng vị trí giữa mảng  **(left+right)/2**.
- **Mô phỏng:**
    - **Input:** Mảng được sắp xếp theo thứ tự và phần tử cần tìm
    - **Output:** Chỉ số vị trí của phần tử cần tìm trong mảng hoặc báo không tìm thấy.
    - **Ý tưởng:**
        - Sắp xếp mảng theo thứ tự tăng dần.
        - So sánh phần tử cần tìm với phần tử ở giữa mảng.
        - Nếu phần tử cần tìm lớn hơn phần tử ở giữa thì ta tìm ở nữa bên phải của mảng và ngược lại.
        - Lặp lại cho đến khi tìm được phần tử cần tìm thì trả về chỉ số của nó, nếu mảng không có phần tử nào giống với phần tử cần tìm thì trả về -1.
- **Cài đặt thuật toán tìm kiếm nhị phân:**

```cpp=
int BinarySearch(int arr[], int n, int x)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == x)
            return mid;
        if (x < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}
```
![Ảnh minh hoạ cho BinarySearch](https://i.imgur.com/vNmB8Hd.gif)

**3. Tìm kiếm nội suy (Interpolation Search)**
- Thuật toán tìm kiếm nội suy là **dạng cải tiến của thuật toán tìm kiếm nhị phân**, có tốc độ tìm kiếm được tối ưu rất cao và nhanh hơn nhiều so với tìm kiếm nhị phân.
- **Ưu điểm**:
    - Tốc độ cao do được tối ưu từ tìm kiếm nhị phân.
    - Nhanh đối với mảng có nhiều phần tử.
- **Nhược điểm**:
    - Mảng phải được sắp xếp theo thứ tự và các phần tử phải phân bố đồng đều trên mảng.

- **Đánh giá:** 
    - Độ phức tạp trung bình **O(log(log(n)))**.
    - Độ phức tạp trong trường hợp xấu nhất là **O(log(log(n)))**.
    - Độ phức tạp trong trường hợp tốt nhất là **O(1)**.
- **Mô phỏng:**
    - **Input:** Mảng đã được sắp xếp theo thứ tự và có sự phân bố đồng đều giữa các phần tử mảng.
    - **Output:** Chỉ số của phần tử cần tìm trong mảng hoặc báo không tìm thấy trong mảng.
    - **Ý tưởng:**
        - **Giả sử chúng ta có:**
            - **left**, **right** là hai vị trí đầu và cuối mảng.
            - **A** là mảng chứa phần tử cần tìm.
            - **X** là giá trị cần tìm.
        - Thay vì xác định điểm **mid** bằng công thức:

        $$ mid = {left+right \over 2} $$

        - Thuật toán tìm kiếm nội suy xác định điểm **mid** bằng công thức sau:

        $$ mid = {left+{ {(right - left)\times(X - A[left])}\over{A[right] - A[left]}}} $$

        - Các bước còn lại thực hiện tương tự thuật toán tìm kiếm nhị phân.
    
- **Cài đặt thuật toán tìm kiếm nội suy:**

```cpp=
int InterpolationSearch(int arr[], int n, int x)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = left + ((right - left) * (x - arr[left])) / (arr[right] - arr[left]);
        if (arr[mid] == x)
            return mid;
        if (x < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}
```


4.  **Tìm kiếm nhị phân dạng cây ( Binary Search Tree)**
- 
