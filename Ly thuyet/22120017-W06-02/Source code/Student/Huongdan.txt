1. Cách chia tỉ lệ cho số lần phát biểu của các sinh viên:
- Bước 1: Đếm số lượng số lần phát biểu dựa trên danh sách sinh viên.
- Bước 2: Tính toán theo công thức val = 100 / (1 + 2 + 3 + ... + n) (n: số lượng số lần phát biểu).
- Bước 3: Lấy kết quả ở trên, sau đó tính tỉ lệ bằng công thức ratio = (val * i) / 100 (i : n -> 1).
Ví dụ: Giả sử số lần phát biểu của các sinh viên lần lượt là: 0, 1, 2, 3, 4, 5
-> Số lượng số lần phát biểu của sinh viên: 6
-> val = 100 / (1 + 2 + 3 + 4 + 5 + 6) = 100/21
-> tỉ lệ của số lần phát biểu 0 là: ratio_0 = (val * 6) / 100 = 2/7 
-> tỉ lệ của số lần phát biểu 1 là: ratio_1 = (val * 5) / 100 = 5/21
-> tỉ lệ của số lần phát biểu 2 là: ratio_2 = (val * 4) / 100 = 4/21
-> tỉ lệ của số lần phát biểu 3 là: ratio_3 = (val * 3) / 100 = 1/7
-> tỉ lệ của số lần phát biểu 4 là: ratio_4 = (val * 2) / 100 = 2/21
-> tỉ lệ của số lần phát biểu 5 là: ratio_5 = (val * 1) / 100 = 1/21

2. Dựa vào tỉ lệ trên cách random ra sinh viên.
- Ở đây, dùng ví dụ trên để miêu tả các random dễ dàng hơn.
- Dựa vào tỉ lệ trên -> dãy số: 2/7  11/21  5/7  6/7  20/21  1 (v[i] = ratio_i + v[i - 1] với i >= 1)
- Sử dụng giá trị ngẫu nhiên trong khoảng (0, 1) để chọn ra sinh viên
. Nếu 0 <= giá trị ngẫu nhiên <= 2/7 => Sinh viên có số lần phát biểu 0 sẽ được gọi
. Nếu 2/7 <= giá trị ngẫu nhiên <= 11/21 => Sinh viên có số lần phát biểu 1 sẽ được gọi
. Nếu 11/21 <= giá trị ngẫu nhiên <= 5/7 => Sinh viên có số lần phát biểu 2 sẽ được gọi
. Nếu 5/7 <= giá trị ngẫu nhiên <= 6/7 => Sinh viên có số lần phát biểu 3 sẽ được gọi
. Nếu 6/7 <= giá trị ngẫu nhiên <= 20/21 => Sinh viên có số lần phát biểu 4 sẽ được gọi
. Nếu 20/21 <= giá trị ngẫu nhiên <= 1 => Sinh viên có số lần phát biểu 5 sẽ được gọi

3. Cách chạy chương trình
- Mỗi lần chạy chương trình là một buổi học. Sau khi kết thúc chương trình và chạy lại thì sẽ là một
buổi học mới và tỉ lệ số lần phát biểu sẽ được tính toán lại.
- Khi chạy chương trình, để tiếp tục chạy chương trình thì nhấn enter, kết thúc chương trình gõ 'exit'.
- Khi tất cả các sinh viên đều đã được gọi chương trình sẽ tự động kết thúc (vì mỗi sinh viên trong một buổi
học không gọi quá 1 lần).

4. Các thuật giải quan trọng trong chương trình
- Phép biến đổi tuyến tính nghịch đảo là một phép biến đổi số học được sử dụng để tăng xác suất cho các giá trị
nhỏ hơn trong một phân phối. Cụ thể, nó chuyển đổi một giá trị đầu vào từ một phân phối đồng đều thành một phân
phối nghịch đảo.
	Công thức chung của phép biến đổi tuyến tính nghịch đảo là:
		y = (a + x^b) * (c - a)
	Trong đó:
	. x là giá trị đầu vào, thường nằm trong khoảng từ 0 đến 1, biểu diễn một phần của phân phối đồng đều.
	. a và c là giá trị nhỏ nhất và lớn nhất trong phạm vi mong muốn của phân phối tuyến tính nghịch đảo.
	. b là một hằng số thể hiện mức độ của phép biến đổi, thường là một số nguyên dương. Giá trị của 
	b sẽ quyết định mức độ tăng xác suất cho các giá trị nhỏ hơn.
	. y là giá trị đầu ra sau khi phép biến đổi được áp dụng.
-> Trong phép biến đổi này, khi x gần 0, x^b sẽ giảm đáng kể, làm tăng đáng kể giá trị của y so với a. 
Điều này dẫn đến việc tăng xác suất cho các giá trị nhỏ hơn trong phân phối. Khi x tiến gần đến 1, giá 
trị của y tiến gần đến c, tức là giá trị lớn nhất trong phạm vi mong muốn.