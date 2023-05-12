import React from 'react'
import './Button.css'
function Button({ text, heading }) {
    return (
        <div>
            <h2>{heading}</h2>
            <button>{text}</button>
        </div>

    )
}

export default Button