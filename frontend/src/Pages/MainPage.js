import React, { useState } from 'react';
import "./mainPages.css";

export function MainPage() {
  const [inputText, setInputText] = useState('');

  const handleSubmit = async (event) => {
    event.preventDefault();
    try {
      const response = await fetch('http://localhost:5000/', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify({ contents: inputText })
      });
      const data = await response.json();
      console.log('Response from server:', data);
    } catch (error) {
      console.error('Error posting data:', error);
    }
  };

  const handleInputChange = (event) => {
    setInputText(event.target.value);
  };

  return (
    <div className="page-container">
      <div className="app-name">SyntaxSeed</div>
      <form className="input-box" onSubmit={handleSubmit}>
        <textarea 
          id="code-input" 
          placeholder='Write your C program here...' 
          value={inputText}
          onChange={handleInputChange}
        ></textarea>
        <button type="submit">Submit</button>
      </form>
    </div>
  );
}
