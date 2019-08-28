#pragma once
namespace psteudo {
	namespace memory {
		class Align {
		public:
			explicit Align(int value);
			int GetValue() const;
		private:
			int m_value;
		};
	}
}
