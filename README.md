# cpp_smartpointers

There are four smart pointers in C++11: <b>std::auto_ptr, std::unique_ptr,
std::shared_ptr, and std::weak_ptr.</b>

<h2>std::auto_ptr<b> [DEPRECATED] </b></h2>

<p>std::auto_ptr was introduced in C++98. In c++98, there was no implemantaion about move semantics yet. Because of that std::auto_ptr use copy operations for move.  Copying an auto_ptr changes the object being copied by setting the contents to NULL.
In c++11 ,for this issue, std::unique_ptr was introduced. std::unique_ptr does everything std::auto_ptr does, plus more. It does it as efficiently, and it does it without warping what it means to copy an object. It’s better than std::auto_ptr in every way.</p>

<h2>std::unique_ptr</h2>
<p>It is a smart pointer which manages for its lifetime. When the object out of scope then its destructor delete automaticly. 
std::unique_ptr is same size as raw pointer and for most operations, they execute exactly the same instructions. If a raw pointer is small enough and fast enough for you, a std::unique_ptr almost certainly is , too.(Effective Modern C++,Item 18)
std::unique_ptr is move-only type. Because if you could copy a std::unique_ptr, you have two std::unique_ptrs to the same resource. İt is a big problem. To prevent this issiue copying not allowed for std::unique_ptr. 
You can define custom deleter function for std::unique_ptr. When you define custom deleter function, its cause grow of the size of std::unique_ptr.(it depend on defined custom deleter function). But if you use lambda expression with no captures, the size of std::unique_ptr doesn't effect.
</p>

<h2>std::shared_ptr</h2>
<p>An object accessed via std::shared_ptrs has its lifetime managed by those pointers through
shared ownership. No specific std::shared_ptr owns the object. Instead, all std::shared_ptrs pointing to it collaborate to ensure its destruction at the point where it’s no longer needed.

A std::shared_ptr can tell whether it’s the last one pointing to a resource by consulting the resource’s reference count, a value associated with the resource that keeps
track of how many std::shared_ptrs point to it. std::shared_ptr constructors
increment this count (usually—see below), std::shared_ptr destructors decrement
it, and copy assignment operators do both.
In general, it’s impossible for a function creating a std::shared_ptr to an object to knowwhether some other std::shared_ptr already points to that object, so the followingrules for control block creation are used:
• std::make_shared always creates a control block.
• A control block is created when a std::shared_ptr is constructed from a unique-ownership pointer (i.e., a std::unique_ptr or std::auto_ptr).
• When a std::shared_ptr constructor is called with a raw pointer, it creates a control block. 
(Effective Modern C++,Item 19)
</p>

<h2>std::weak_ptr</h2>
<p>a pointer like std::shared_ptr that doesn’t affect an object’s reference count. This kind of smart pointer has to contend
with a problem unknown to std::shared_ptrs: the possibility that what it points to has been destroyed. A truly smart pointer would deal with this problem by tracking when it dangles, i.e., when the object it is supposed to point to no longer exists. That’s precisely the kind of smart pointer std::weak_ptr is.
std::weak_ptrs can’t be dereferenced, nor can they be tested for nullness.
That’s because std::weak_ptr isn’t a standalone smart pointer. It’s an augmentation of std::shared_ptr.
(Effective Modern C++,Item 20)
</p>
