#pragma once

template <unsigned int size, typename T>
class cTkFixedString
{
public: 
	cTkFixedString()
	{ };

	cTkFixedString(const char* buff)
	{
		strcpy_s(macBuffer, size, buff);
	}

	T macBuffer[size];

    //TODO: actually implement this
    void Copy(const char* lpacBuffer)
    {
        int v2; // r8d
        const char* v3; // rax

        v2 = 0;
        v3 = lpacBuffer + 2;
        while (*(v3 - 2))
        {
            if (!*(v3 - 1))
            {
                v2 += 2;
                goto LABEL_11;
            }
            if (!*v3)
            {
                v2 += 3;
                goto LABEL_11;
            }
            v2 += 4;
            if (v3[1])
            {
                v3 += 4;
                if ((__int64)&v3[-2i64 - (__int64)lpacBuffer] < 128)
                    continue;
            }
            goto LABEL_11;
        }
        ++v2;
    LABEL_11:
        memmove(this, lpacBuffer, v2);
        this->macBuffer[127] = 0;
    }
};