# To Do

- [ ] xml parser
  - [ ] from string
  - [ ] from stream
  
- [ ] handle encoding

- [ ] Better handling of attributes

- [ ] documentation

- [ ] append: Handle infinite recusivity

  1. Check if rcount = 1 (safe case to append)

  2. example case 

     ```c++
     node1.append(node2);
     ```

     check RECURSIVELY if node1 is a child of node2
     if yes:

     ​	throw an error

  Should it be a safe version of append? (void add(...) which would copy/rcopy ?)

- [ ] Spécial nodes:

  - [ ] Commentary
  - [ ] Text

- [ ] Handle case where name is empty (for nodes and for attributes)

- [ ] Add class Document



## Html extension

- [ ] Create node specialization for html

- [ ] make such code possible:

  ```c++
  Node root = html > {
  	p
  		+ Class("abc def")
  		+ Attr("style", "color:red;")
  		>
  			div >
  				Text("Hello"),
  	p + Class("abc")
  }
  ```

  that would generate

  ```html
  <html>
      <p class="abc def" style="color:red;">
          <div>
          	Hello    
      	</div>
      </p>
  	<p class="abc"/> 
  </html>
  ```

  