#ifndef ENCODER_POLAR_MK_SYS_HPP_
#define ENCODER_POLAR_MK_SYS_HPP_

#include "Encoder_polar_MK.hpp"

namespace aff3ct
{
namespace module
{
template <typename B = int>
class Encoder_polar_MK_sys : public Encoder_polar_MK<B>
{
public:
	Encoder_polar_MK_sys(const int& K, const int& N, const std::vector<bool>& frozen_bits,
	                     const std::vector<std::vector<bool>>& kernel_matrix = {{1,0},{1,1}}, const int n_frames = 1);

	Encoder_polar_MK_sys(const int& K, const int& N, const std::vector<bool>& frozen_bits,
	                     const std::vector<std::vector<std::vector<bool>>>& kernel_matrices,
	                     const std::vector<uint32_t> &stages, const int n_frames = 1);

	Encoder_polar_MK_sys(const int& K, const int& N, const std::vector<bool>& frozen_bits, const std::string &code_path,
	                     const int n_frames = 1);

	virtual ~Encoder_polar_MK_sys() = default;

	void init();

protected:
	virtual void _encode(const B *U_K, B *X_N, const int frame_id);
};
}
}

#endif // ENCODER_POLAR_MK_SYS_HPP_
