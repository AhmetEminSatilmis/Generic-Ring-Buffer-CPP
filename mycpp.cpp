#include <iostream>
using namespace std;

template <typename T, int SIZE>
class RingBuffer
{
	private:
		T buffer[SIZE];
		int head;
		int tail;
		bool is_full;
	public:
		RingBuffer(): head(0), tail(0), is_full(false)
		{
			cout << "[SYSTEM] New buffer is created. Size: " << SIZE << endl;
		}
		
		bool Write(T data)
		{
			if (is_full)
			{
				return false;
			}
			buffer[head] = data;
			head = (head + 1) % SIZE;
			if (head == tail)
			{
				is_full = true;
			}
			cout << "Data: " << data << " is written on the index: " << (head == 0 ? SIZE - 1 : head - 1) << endl;
			return true;
		}
		bool Read(T &data)
		{
			if (head == tail && !is_full)
			{
				return false;
			}
			data = buffer[tail];
			tail = (tail + 1) % SIZE;
			is_full = false;
			cout << "Data: " << data << " is read. The next index to read is: " << tail << endl;
			return true;
		}
};

int main()
{
	cout << "INT BUFFER TEST (GPS Coordinates)\n";
	RingBuffer<int, 5> gpsBuffer;
	if (!gpsBuffer.Write(100))
	{
		cout << "Data: 100 could not be written buffer is full\n";
	}
	if (!gpsBuffer.Write(200))
	{
		cout << "Data: 200 could not be written buffer is full\n";
	}
	int readGps;
	if (!gpsBuffer.Read(readGps))
	{
		cout << "[ERROR] buffer is empty, no value to read.\n";
	}
	
	cout << "\n\n\nFLOAT BUFFER TEST (Temperature)\n";

	RingBuffer<float, 3> tempBuffer;

	if (!tempBuffer.Write(24.5f))
	{
		cout << "Data: 24.5 could not be written buffer is full\n";
	}
	if (!tempBuffer.Write(25.1f))
	{
		cout << "Data: 25.1 could not be written buffer is full\n";
	}
	float readTemp;
	if (!tempBuffer.Read(readTemp))
	{
		cout << "[ERROR] buffer is empty, no value to read.\n";
	}
	return 0;
}
















