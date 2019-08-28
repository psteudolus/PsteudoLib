#include "Align.h"
namespace psteudo {
	namespace memory {
		Align::Align(int value) : m_value(value) {

		}

		int Align::GetValue() const {
			return m_value;
		}
	}
}
