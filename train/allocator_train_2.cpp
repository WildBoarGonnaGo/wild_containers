/*
Аллокатор

1.  placement-new - такой оператор, который берет указатель, и на этот
указатель вызывают явно конструктор того типа, который мы указали
	new (p) T ( );
Эта запись означает, что по адресу p мы направляем конструктор T()
при этом память мы не выделяем
Чтобы явно вызвать декструктор по адресу:
	p -> ~T();
2. Перегрузка operator new
Допустим, в глобальной области видимости пишем
	class C {
		static void	*operator new(size_t n, void *p) {
			::operator new();
			return (p);
		}
	};
	Оператор new делает 2 вещи:
	2.1 Вызывает функцию, которая называется operator new()
	2.2 По тому типу, что она возвращает, вызывает конструктор
3. Если был реализован кастомный оператор new со своими параметрами,
то и delete надо делать соответствующий
4. Есть один уникальный случай, когда компилятор пробрасывает кастомный delete ->
	в случае если в кастомном new присутствует исключение
5. 
template <class T> struct std::allocator<T> {
	T*		allocate(size_t n) const {
		return ( (T*)(new char n * sizeof(T)));
	} -> выделяет память, но конструктор еще не вызывает
	если deallocate передадим неправильный размер, то undefined behavior (UB)
	void	deallocate(T* p, size_t n) const{
		delete[] (char *)p;
	}
	template <typename ... Args>
	void	construct(T *p, const Args	args) const{
		return (new (p) T(args...));
	}
	void	destroy(T* p) const {
		p->~T();
	};
}

*/