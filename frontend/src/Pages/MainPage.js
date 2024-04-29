import React from 'react';
import "./mainPages.css";

export function MainPage() {
  return (
    <div className="page-container">
      <div className="app-name">SyntaxSeed</div>
      <form className="input-box" onSubmit={handleSubmit}>
        <textarea id="code-input" placeholder='Write your C program here...'></textarea>
        <button type="submit">Submit</button>
      </form>
    </div>
  );
}

// Example submit handler function
function handleSubmit(event) {
  event.preventDefault();
  // Here you can handle the submission, e.g., logging the input or sending to a server
  console.log(document.getElementById('code-input').value);
}
