 // String(const String &other)
    // :m_size(other.m_size)
    // {
    //     m_buffer = new char[m_size + 1];
    //     memcpy(m_buffer, other.m_buffer, m_size + 1);   //i have used +1 beacause i know that the string xoming here is already null terminated 
    //     //so we donot have to use m_buffer[m_size] = 0;   like above 

    // }