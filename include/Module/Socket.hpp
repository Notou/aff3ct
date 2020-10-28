/*!
 * \file
 * \brief Class module::Socket.
 */
#ifndef SOCKET_HPP_
#define SOCKET_HPP_

#include <string>
#include <memory>
#include <vector>
#include <cstddef>
#include <typeindex>

#include "Tools/Interface/Interface_reset.hpp"
#include "Module/Task.hpp"

namespace aff3ct
{
namespace module
{
class Socket : public tools::Interface_reset
{
#ifndef DOXYGEN_SHOULD_SKIP_THIS
	friend Task;
#endif
protected:
	Task &task;

	const std::string          name;
	const std::type_index      datatype;
	      size_t               databytes;
	      bool                 fast;
	      void*                dataptr;
	      std::vector<Socket*> bound_sockets;
	      Socket*              bound_socket;

public:
	inline Socket(Task &task, const std::string &name, const std::type_index datatype, const size_t databytes,
	              const bool fast = false, void *dataptr = nullptr);
	virtual ~Socket() = default;

	inline const std::string&          get_name           () const;
	inline const std::type_index&      get_datatype       () const;
	inline const std::string&          get_datatype_string() const;
	inline uint8_t                     get_datatype_size  () const;
	inline size_t                      get_databytes      () const;
	inline size_t                      get_n_elmts        () const;
	inline void*                       get_dataptr        () const;
	inline bool                        is_fast            () const;
	inline Task&                       get_task           () const;
	inline const std::vector<Socket*>& get_bound_sockets  () const;
	inline const Socket&               get_bound_socket   () const;
	inline       Socket&               get_bound_socket   ();

	inline void set_fast(const bool fast);

	inline void bind(Socket &s_out, const int priority = -1);

	inline void operator()(Socket &s_out, const int priority = -1);

	template <typename T, class A = std::allocator<T>>
	inline void bind(std::vector<T,A> &vector);

	template <typename T, class A = std::allocator<T>>
	inline void operator()(std::vector<T,A> &vector);

	template <typename T>
	inline void bind(T *array);

	template <typename T>
	inline void operator()(T *array);

	inline void bind(void* dataptr);

	inline void operator()(void* dataptr);

	inline void reset();

	inline size_t unbind(Socket& s_out);

protected:
	inline void set_databytes(const size_t databytes);
};
}
}

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include "Module/Socket.hxx"
#endif

#endif /* SOCKET_HPP_ */
