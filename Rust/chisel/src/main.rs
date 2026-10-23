// Chisel
//
// A simple code formatting tool.
//
// by Nano

fn main() {
    println!("Hello, world!");
}

fn names_can_begin_with(c: char) -> bool {
    c.is_ascii_alphabetic() || c == '_'
}

fn names_can_contain(c: char) -> bool {
    c.is_ascii_alphanumeric() || c == '_'
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_names_begin_with() {
        for c in char::MIN..=char::MAX {
            match c {
                '_' | 'a'..='z' | 'A'..='Z' => assert!(names_can_begin_with(c)),
                _ => assert!(!names_can_begin_with(c)),
            }
        }
    }

    #[test]
    fn test_names_can_contain() {
        for c in char::MIN..=char::MAX {
            match c {
                '_' | 'a'..='z' | 'A'..='Z' | '0'..='9' => assert!(names_can_contain(c)),
                _ => assert!(!names_can_contain(c)),
            }
        }
    }
}
